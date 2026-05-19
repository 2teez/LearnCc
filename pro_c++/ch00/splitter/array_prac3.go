package main

import (
	"fmt"
)

func main() {
	array := []int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
	even, odd := separateEvenOdd(array)
	fmt.Println("Even:", even)
	fmt.Println("Odd:", odd)
}

func separateEvenOdd(array []int) (even, odd []int) {
	for _, num := range array {
		if num%2 == 0 {
			even = append(even, num)
		} else {
			odd = append(odd, num)
		}
	}
	return
}
