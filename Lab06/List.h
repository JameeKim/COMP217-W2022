/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Lab #6 (due Sun. Feb. 27, 2022)
 *
 * 301058465 Dohyun Kim
 */

#pragma once

#include <algorithm>
#include <iterator>
#include <memory>
#include <type_traits>
#include <utility>

namespace list
{
    template <class T>
    class List;

    template <class T>
    class Node;

    template <class T>
    using node_ptr = std::shared_ptr<Node<T>>;

    /**
     * The node used in the list
     */
    template <class T>
    class Node
    {
    public:
        static node_ptr<T> make(T value)
        {
            return std::make_shared<Node>(value);
        }

        static node_ptr<T> make(T value, const node_ptr<T>& next)
        {
            return std::make_shared<Node>(value, next);
        }

        explicit Node(const T value) noexcept
            : nextNode(nullptr), val(value) {}

        explicit Node(const T value, node_ptr<T> next)
            : nextNode(std::move(next)), val(value) {}

        node_ptr<T> next() const noexcept { return nextNode; }

        node_ptr<T> next(node_ptr<T> node) noexcept
        {
            std::swap(nextNode, node);
            return node;
        }

        const T& value() const noexcept { return val; }
        T& value() noexcept { return val; }

        T value(T newVal) noexcept
        {
            std::swap(val, newVal);
            return newVal;
        }

    private:
        std::shared_ptr<Node> nextNode;
        T val;
    };

    /**
     * Constant iterator for the list
     */
    template <class T, class L = List<T>>
    class ListConstIterator
    {
        friend class List<T>;

    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type        = typename L::value_type;
        using difference_type   = typename L::difference_type;
        using pointer           = typename L::const_pointer;
        using reference         = typename L::const_reference;

        ListConstIterator() noexcept : node(nullptr), isValid(false) {}

    protected:
        explicit ListConstIterator(
            node_ptr<T> node,
            const bool isValid = true) noexcept
            : node(std::move(node)), isValid(isValid) {}

    public:
        reference operator*() const noexcept
        {
            return node->value();
        }

        pointer operator->() const noexcept
        {
            return &node->value();
        }

        bool operator==(const ListConstIterator<T, L>& rhs) const noexcept
        {
            return node == rhs.node;
        }

        bool operator!=(const ListConstIterator<T, L>& rhs) const noexcept
        {
            return !(*this == rhs);
        }

        ListConstIterator<T>& operator++() noexcept
        {
            node = node->next();
            return *this;
        }

        constexpr node_ptr<T> getNode() const { return node; }

    protected:
        node_ptr<T> node;
        bool isValid;
    };

    template <class T, class L = List<T>>
    class ListIterator : public ListConstIterator<T, L>
    {
        friend class List<T>;

    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type        = typename L::value_type;
        using difference_type   = typename L::difference_type;
        using pointer           = typename L::pointer;
        using reference         = typename L::reference;

        ListIterator() noexcept : ListConstIterator<T, L>() {}

    protected:
        explicit ListIterator(node_ptr<T> node, const bool isValid = true) noexcept
            : ListConstIterator<T, L>(node, isValid) {}

    public:
        reference operator*() const noexcept
        {
            return this->node->value();
        }

        pointer operator->() const noexcept
        {
            return &this->node->value();
        }

        bool operator==(const ListIterator<T, L>& rhs) const noexcept
        {
            return this->node == rhs.node;
        }

        bool operator!=(const ListIterator<T, L>& rhs) const noexcept
        {
            return !(*this == rhs);
        }
    };

    /**
     * A singly linked list using the node above
     */
    template <class T>
    class List
    {
    public:
        using value_type = T;
        using reference = T&;
        using const_reference = const T&;
        using pointer = T*;
        using const_pointer = const T*;
        using difference_type = ptrdiff_t;
        using size_type = size_t;
        using const_iterator = ListConstIterator<T>;
        using iterator = ListIterator<T>;

        List() noexcept : head(nullptr) {}

        List(const std::initializer_list<T> l)
        {
            if (l.size() <= 0)
                return;

            auto it = l.begin();
            head = std::make_shared<Node<T>>(*it);
            ++it;

            for (node_ptr<T> n = head; it != l.end(); ++it, n = n->next())
            {
                n->next(std::make_shared<Node<T>>(*it));
            }
        }

        explicit List(node_ptr<T> n) : head(std::move(n)) {}

        iterator before_begin()
        {
            const node_ptr<T> n = std::make_shared<Node<T>>();
            n->next(head);
            return iterator(n, false);
        }

        const_iterator before_begin() const
        {
            const node_ptr<T> n = std::make_shared<Node<T>>();
            n->next(head);
            return const_iterator(n, false);
        }

        iterator begin() noexcept { return iterator(head); }

        const_iterator begin() const noexcept { return const_iterator(head); }

        iterator end() noexcept { return iterator(nullptr); }

        const_iterator end() const noexcept
        {
            return const_iterator(nullptr);
        }

        template <class... Args>
        void push(Args&&... args)
        {
            node_ptr<T> n = std::make_shared<Node<T>>(
                std::forward<Args>(args)...);
            n->next(head);
            head = std::move(n);
        }

        T pop()
        {
            const T v = head->value();
            head = head->next();
            return v;
        }

    private:
        node_ptr<T> head;
    };

    /**
     * Custom comparator for node pointers and node iterators
     */
    template <class T>
    struct NodeAddrCmp
    {
        constexpr bool operator()(
            const node_ptr<T>& lhs,
            const node_ptr<T>& rhs) const
        {
            return std::addressof(*lhs) < std::addressof(*rhs);
        }

        constexpr bool operator()(
            const ListConstIterator<T>& lhs,
            const ListConstIterator<T>& rhs) const
        {
            return std::addressof(*lhs.getNode())
                < std::addressof(*rhs.getNode());
        }

        constexpr bool operator()(
            const ListIterator<T>& lhs,
            const ListIterator<T>& rhs) const
        {
            return std::addressof(*lhs.getNode())
                < std::addressof(*rhs.getNode());
        }
    };
}
