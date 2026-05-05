package main

import "fmt"

func main() {

	c := NewCalculator(Add)
	result := c.Calculate(5, 3)
	fmt.Println(result)

}
