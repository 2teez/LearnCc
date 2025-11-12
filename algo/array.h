
#ifndef __ARRAY__
#define __ARRAY__
// include the structure of the header file
#include <iostream>

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
