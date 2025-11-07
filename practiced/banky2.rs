#![deny(clippy::all, clippy::pedantic, unused)]

trait Logger {
    fn log(&self, from: usize, to: usize, amt: f64);
}

fn main() {
    let mut bank = Bank::new();
    bank.make_transfer(1000, 2000, 49.95);
    bank.make_transfer(2000, 4000, 20.0);
    bank.set_logger(Box::new(FileLogger));
    bank.make_transfer(3000, 2000, 75.00);
}

struct Bank {
    log: Box<dyn Logger>,
}

impl Bank {
    fn new() -> Self {
        Self {
            log: Box::new(ConsoleLogger),
        }
    }

    fn make_transfer(&self, from: usize, to: usize, amount: f64) {
        self.log.log(from, to, amount);
    }

    fn set_logger(&mut self, logger: Box<dyn Logger>) {
        self.log = logger;
    }
}

#[derive(Debug)]
struct ConsoleLogger;

impl Logger for ConsoleLogger {
    fn log(&self, from: usize, to: usize, amt: f64) {
        println!("[Console] {} -> {}: {}", from, to, amt);
    }
}

#[derive(Debug)]
struct FileLogger;

impl Logger for FileLogger {
    fn log(&self, from: usize, to: usize, amt: f64) {
        println!("[File] {}, {}: {}", from, to, amt);
    }
}
