#ifndef PRIORITY_QUEUE_HPP
#define PRIORITY_QUEUE_HPP

#include <vector>

namespace ds {
    template<typename T, typename C = std::greater<T>>
    class priority_queue {
    public:
        using value_type = T;
        using reference = T&;
        using const_reference = T const&;
        using pointer = T*;
        using const_pointer = T const*;
        using size_type = std::size_t;
        using difference = std::ptrdiff_t;

        explicit priority_queue(C comp = C{});
        priority_queue(priority_queue const&) = default;
        priority_queue(priority_queue &&) noexcept = default;
        priority_queue& operator=(priority_queue const&) = default;
        priority_queue& operator=(priority_queue &&) noexcept = default;
        template<typename U>
        void push_back(U&& v); 
        void pop_front();
        const_reference top() const noexcept;
        size_type size() const noexcept;
        bool empty() const noexcept;
        ~priority_queue() = default;
    private:
        void swim(size_type index);
        void sink(size_type index);
        C comp_;
        size_type size_{};
        std::vector<T> elements_;
    };

    template<typename T, typename C>
    priority_queue<T, C>::priority_queue(C comp) 
        : comp_(comp)
    {
    }

    template<typename T, typename C>
    template<typename U>
    void priority_queue<T, C>::push_back(U&& v) {
        elements_.push_back(std::forward<U>(v));
        ++size_;
        swim(size_ - 1);
    }

    template<typename T, typename C>
    void priority_queue<T, C>::pop_front() {
        using std::swap;

        swap(elements_[0], elements_[size_ - 1]);
        elements_.pop_back();

        --size_;
        if(size_ > 0)
            sink(0);
    }

    template<typename T, typename C>
    typename priority_queue<T,C>::const_reference priority_queue<T, C>::top() const noexcept {
        return elements_.at(0);
    }

    template<typename T, typename C>
    typename priority_queue<T,C>::size_type priority_queue<T, C>::size() const noexcept {
        return size_;
    }

    template<typename T, typename C>
    bool priority_queue<T, C>::empty() const noexcept {
        return size_ == 0;
    }

    template<typename T, typename C>
    void priority_queue<T, C>::swim(typename priority_queue<T,C>::size_type index) {
        while(index > 0 ) {
            auto parent = (index - 1) / 2; 
            if(comp_(elements_[parent], elements_[index]))
                break;
            using std::swap;
            swap(elements_[parent], elements_[index]);
            index = parent;
        }
    }

    template<typename T, typename C>
    void priority_queue<T, C>::sink(typename priority_queue<T,C>::size_type index) {
        while(index < size_) {
            auto l = index * 2 + 1;
            auto r = index * 2 + 2;

            auto m = index;
            
            if(l < size_ && comp_(elements_[l] , elements_[m])) m = l;
            if(r < size_ && comp_(elements_[r] , elements_[m])) m = r;
            
            if(index == m) break;
            using std::swap;

            swap(elements_[m], elements_[index]);
            index = m;
        }
    }
}

#endif
