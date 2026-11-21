
#ifndef __ARRAY__
#define __ARRAY__
// include the structure of the header file
#include <iostream>
#include <stdexcept>

template <typename T>
struct Array
{
    explicit Array(): size{10}, index{0}, _array(nullptr)
    {
        _array = new T[size]{};
    }
    explicit Array(size_t msize) : size{msize}, index{0}, _array(nullptr)
    {
        _array = new T[msize]{};
    }

    Array(const T* arr, size_t n): size{n}, index {arr? size: 0}, _array{new T[size]}
    {
        if (arr)
        {
           for (size_t i = 0; i < size; i++)
           {
               _array[i] = arr[i];
           }
        }
    }

    T pop()
    {

        if (index == 0 || !_array)
            throw std::out_of_range("Array is empty!");

        index = index - 1;
        T result = _array[index];

        auto new_arr = new T[index];
        for(size_t i = 0; i < index; i++)
            new_arr[i] = _array[i];
        delete[] _array;
        _array = new_arr;

        return result;
    }

    bool remove_at(size_t idx)
    {
        if (index == 0 || idx > index || !_array)
            return false;

        auto new_arr = new T[index];
        size_t counter = 0;
        for(size_t i = 0; i < index; i++)
            if (idx != i)
                new_arr[counter++] = _array[i];

        delete[] _array;
        _array = new_arr;

        return true;

    }

    Array(const Array<T>& arr): size {arr.size}, index {size}
    {
            _array = new T[arr.size]{};
           for (size_t i = 0; i < arr.size; i++)
           {
               _array[i] = arr[i];
           }
    }
    Array& operator=(const Array&) = default;

    Array(Array&&) noexcept = default;

    Array& operator=(Array&&) noexcept = default;

    const T& operator[](size_t index) const
    {
        return _array[index];
    }

    constexpr bool push(const T& value)
    {
        if (index < size)
        {
            _array[index] = value;
            index += 1;
            return true;
        }
        return false;
    }

    Array& push(const T& value, size_t nindex)
    {
        if (nindex < size)
        {
            _array[nindex] = value;
            return *this;
        }
        return *this;
    }

    bool contains(T const& value) const noexcept
    {
        for (size_t i = 0; i < index; i++)
        {
            if (_array[i] == value)
                return true;
        }
        return false;
    }

    friend std::ostream& operator<<(std::ostream& os, const Array<T>& arr)
    {
        if (arr.index == 0)
        {
            os << "Empty Array...";
            return os;
        }
        os << "[";
        for (size_t i = 0; i < arr.index; ++i)
        {
            if (i) os << ", ";
            os << arr[i];
        }

        return os << "]";
    }

    ~Array()
    {
        delete[] _array;
    }
    private:
      size_t size;
      size_t index;
      T* _array;
};

#endif //__ARRAY__
