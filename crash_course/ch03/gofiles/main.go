package main

func main() {
	bank := NewBank()
	bank.MakeTransfer(1000, 2000, 49.95)
	bank.MakeTransfer(2000, 4000, 20.00)
	bank.SetLogger(&FileLogger{})
	bank.MakeTransfer(3000, 2000, 75.00)
}
