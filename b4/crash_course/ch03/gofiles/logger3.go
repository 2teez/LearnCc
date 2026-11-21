package main

import "fmt"

type Logger interface {
	Log(from, to uint64, amount float64)
}

type ConsoleLogger struct{}

func (c *ConsoleLogger) Log(from, to uint64, amount float64) {
	fmt.Printf("[Cons] %d -> %d: %.6f\n", from, to, amount)
}

type FileLogger struct{}

func (f *FileLogger) Log(from, to uint64, amount float64) {
	fmt.Printf("[File] %d -> %d: %.6f\n", from, to, amount)
}

type Bank struct {
	Logger
}

func NewBank() *Bank {
	return &Bank{Logger: &ConsoleLogger{}}
}

func (b *Bank) SetLogger(logger Logger) {
	b.Logger = logger
}

func (b *Bank) MakeTransfer(from, to uint64, amount float64) {
	b.Log(from, to, amount)
}
