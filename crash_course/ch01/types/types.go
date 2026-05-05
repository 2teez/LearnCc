package main

const (
	Add = iota
	Subtract
	Multiply
	Divide
)

type Calculator struct {
	op int
}

func (c *Calculator) Calculate(a, b int) int {
	switch c.op {
	case Add:
		return a + b
	case Subtract:
		return a - b
	case Multiply:
		return a * b
	case Divide:
		return a / b
	default:
		return 0
	}
}

func NewCalculator(op int) *Calculator {
	return &Calculator{op: op}
}
