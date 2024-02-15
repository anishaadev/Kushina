#pragma once

#ifndef KUSHINA_ARRAY_KIT_HPP
#define KUSHINA_ARRAY_KIT_HPP

#include "defines.hpp"

namespace kushina::array_kit {
    template<typename TYPE>
    class Array final {
    private:
        TYPE* _data;
        usize_t _size;
    public:
        __KUSHINA__INLINE Array(usize_t size) {
            _size = size;

            _data = new TYPE[size];
        }

        __KUSHINA__INLINE ~Array() {
            delete[] _data;

            _data = KUSHINA_NULL;
            _size = KUSHINA_NULL;
        }

        __KUSHINA_NODISCARD __KUSHINA__INLINE auto size() const KUSHINA_NOEXCEPT -> usize_t {
            return _size;
        }

        __KUSHINA_NODISCARD __KUSHINA__INLINE auto get(usize_t index) const KUSHINA_NOEXCEPT -> TYPE* {
            if(index >= _size) {
                return KUSHINA_NULL;
            }

            return _data + _size;
        }

        //operators
        __KUSHINA_NODISCARD __KUSHINA__INLINE TYPE operator [] (int index) const {
            return _data[index];
        }
        __KUSHINA_NODISCARD __KUSHINA__INLINE TYPE& operator [] (int index) {
            return _data[index];
        }

        __KUSHINA__INLINE Array(Array<TYPE>& other)
        {
            _size = other._size;
            _data = new TYPE[_size];
            memcpy(_data, other._data, _size * sizeof(TYPE));
        }

        __KUSHINA__INLINE Array(Array<TYPE>&& other) KUSHINA_NOEXCEPT {
            _size = other._size;
            _data = other._data;
        }
    };
}

#endif //KUSHINA_ARRAY_KIT_HPP