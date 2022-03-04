/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Mid-Term Exam (Wed. Mar. 2, 2022)
 *
 * 301058465 Dohyun Kim
 */

#pragma once

#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

namespace Bank
{
    /**
     * The type of currency
     */
    using Currency = float;

    /**
     * The type of date
     */
    using Date = unsigned int;

    // Forward declaration
    class Customer;

    /**
     * The base type of all bank cards
     */
    class Card
    {
    public:
        /**
         * The type of card number
         */
        using Number = std::array<char, 16>;

    protected:
        Number num; // card number
        Customer* hold; // holder

        // Only the inheriting classes can construct this
        constexpr explicit Card(
            const Number number,
            Customer* holder = nullptr) noexcept
            : num(number), hold(holder)
        {
        }

    public:
        // Make the destructor virtual because we don't know what the inheriting
        // classes would want to do in the destructor
        // (e.g., CreditCard below has a field of type string)
        virtual ~Card() = default;

        /**
         * The card number
         */
        constexpr Number number() const noexcept { return num; }

        /**
         * The holder of this card
         */
        constexpr Customer* holder() const noexcept { return hold; }

        /**
         * Change the holder of this card
         */
        constexpr Customer* holder(Customer* other) noexcept
        {
            const auto tmp = hold;
            hold = other;
            return tmp;
        }

        /**
         * Attempt a transaction with the given amount
         */
        virtual bool purchase(Currency amount) noexcept = 0;

        // Just a little bit of helper for printing the number
        std::ostream& printNumber(std::ostream& os) const
        {
            return os << "Card " << num[0] << num[1] << num[2] << num[3]
                << "-" << num[4] << num[5] << num[6] << num[7]
                << "-" << num[8] << num[9] << num[10] << num[11];
        }

        virtual std::ostream& print(std::ostream& os) const
        {
            return printNumber(os);
        }
    }; // class Card

    /**
     * A credit card
     */
    class CreditCard : public Card
    {
    public:
        /**
         * The type of credit card providers
         */
        using Provider = std::string;

    protected:
        Provider ins; // institution
        Date exp; // expiry date
        Currency lim; // limit
        Currency bal; // balance

    public:
        explicit CreditCard(
            const Number number,
            Provider provider,
            const Date expiry,
            const Currency limit,
            const Currency balance = 0.0,
            Customer* holder = nullptr) noexcept
            : Card(number, holder),
              ins(std::move(provider)),
              exp(expiry),
              lim(limit),
              bal(balance)
        {
        }

        explicit CreditCard(
            const Number number,
            Provider provider,
            const Date expiry,
            const Currency limit,
            Customer* holder = nullptr,
            const Currency balance = 0.0) noexcept
            : Card(number, holder),
              ins(std::move(provider)),
              exp(expiry),
              lim(limit),
              bal(balance)
        {
        }

        /**
         * The institution that provides the card
         */
        constexpr const Provider& provider() const noexcept { return ins; }

        /**
         * The expiry date of the card
         */
        constexpr const Date& expiry() const noexcept { return exp; }

        /**
         * The maximum balance the card can reach
         */
        constexpr const Currency& limit() const noexcept { return lim; }

        /**
         * Set the limit
         */
        constexpr void limit(const Currency other) noexcept { lim = other; }

        /**
         * Current balance
         */
        constexpr Currency balance() const noexcept { return bal; }

        /**
         * Amount of currency this card can be used for
         */
        constexpr Currency credit() const noexcept { return lim - bal; }

        /**
         * Attempt a transaction with the given amount
         */
        bool purchase(const Currency amount) noexcept override
        {
            const bool purchasable = credit() >= amount;
            this->printNumber(std::cout);

            if (purchasable)
            {
                bal += amount;
                std::cout << " is used to pay " << amount << std::endl;
            }
            else
            {
                std::cout << " cannot pay " << amount << std::endl;
            }

            return purchasable;
        }

        std::ostream& print(std::ostream& os) const override
        {
            return Card::print(os) << " (" << provider() << ") by "
                << expiry() << " with " << balance() << " / " << limit();
        }
    }; // class CreditCard

    /**
     * A credit card with reward points
     */
    class RewardCard : public CreditCard
    {
    public:
        /**
         * The type of reward points
         */
        using Points = int;

    protected:
        Points pts; // reward points

    public:
        // Just trying to feel smart here by not repeating the constructors
        template <class ...Args>
        explicit RewardCard(Args&&... args)
            : CreditCard(args...), pts(0)
        {
        }

        /**
         * Reward points the card holds
         */
        constexpr Points points() const noexcept { return pts; }

        /**
         * Attempt a transaction with the given amount and add the reward points
         * if applicable
         */
        bool purchase(const Currency amount) noexcept override
        {
            const bool result = CreditCard::purchase(amount);

            // We probably shouldn't subtract the reward points when the
            // customer pays the balance (i.e., amount < 0)
            if (result && amount > 0)
            {
                pts += static_cast<Points>(amount); // truncate decimals
            }

            return result;
        }

        std::ostream& print(std::ostream& os) const override
        {
            return CreditCard::print(os) << " (" << points() << " pts)";
        }
    }; // class RewardCard

    /**
     * A customer who can hold several bank cards
     */
    class Customer
    {
        std::string nm; // name
        Date birth; // birthDate
        std::string add; // address
        std::vector<Card*> crd; // cards

    public:
        Customer(
            std::string name,
            const Date birthDate,
            std::string address,
            const std::initializer_list<Card*>& cards = {})
            : nm(std::move(name)),
              birth(birthDate),
              add(std::move(address))
        {
            crd.reserve(cards.size());

            for (Card* c : cards)
            {
                c->holder(this);
                crd.push_back(c);
            }
        }

        /**
         * The name of the customer
         */
        constexpr const std::string& name() const noexcept { return nm; }

        /**
         * The date of birth
         */
        constexpr Date birthDate() const noexcept { return birth; }

        /**
         * The address of the customer
         */
        constexpr const std::string& address() const noexcept { return add; }

        /**
         * The cards that the customer currently has
         */
        constexpr const std::vector<Card*>& cards() const noexcept { return crd; }
        constexpr std::vector<Card*>& cards() noexcept { return crd; }

        /**
         * Pay the given amount with the first card in the list that can pay for
         * it
         */
        bool pay(const Currency amount)
        {
            std::cout << name() << " wants to pay " << amount << std::endl;

            const auto result = std::find_if(
                crd.begin(),
                crd.end(),
                [&](Card* c) { return payWithCard(c, amount); });

            if (result != crd.end())
            {
                std::cout << name() << " paid " << amount << " with ";
                (*result)->printNumber(std::cout) << std::endl;
                return true;
            }

            std::cout << name() << " cannot pay " << amount << " with their "
                << crd.size() << " cards" << std::endl;
            return false;
        }

        /**
         * Attempt to pay the amount with the card
         */
        bool payWithCard(Card* card, const Currency amount)
        {
            if (card->holder() == this)
            {
                return card->purchase(amount);
            }

            card->printNumber(std::cout) << " is not " << name()
                << "'s card; skipping" << std::endl;
            return false;
        }
    };
}

// Just a printing function for the cards
inline std::ostream& operator<<(std::ostream& os, const Bank::Card* card)
{
    return card->print(os);
}
