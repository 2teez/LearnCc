#![deny(clippy::all, clippy::pedantic, unused)]

#[derive(Debug, Clone)]
struct Queue<T> {
    data: Vec<T>,
    size: usize,
    put_count: usize,
    get_count: usize,
}

impl<T> Queue<T>
where
    T: std::fmt::Debug + PartialEq + Clone,
{
    fn new(data: Vec<T>, size: usize) -> Self {
        Self {
            data,
            size,
            put_count: 0,
            get_count: 0,
        }
    }

    ///```
    /// use ::self::Queue;
    /// let mut q = Queue::<u8>::new(vec![1,2], 2);
    /// assert_eq!(Some(2), q.get());
    ///```
    fn get(&mut self) -> Option<T> {
        if self.data.len() == 0 {
            println!("Empty Queue...");
            return None;
        } else if self.size == self.get_count {
            println!("Queue Done!");
            return None;
        }
        self.get_count += 1;
        Some(self.data[self.get_count - 1].clone())
    }

    fn put(&mut self, data: T) -> bool {
        if self.size == self.put_count {
            println!("Queue is Full!");
            return false;
        }
        self.put_count += 1;
        self.data.push(data);
        true
    }
}

fn main() {
    let mut queue: Queue<u8> = Queue::new(vec![], 3);
    println!("{:?} {:?}, {:?}", queue, queue.data, queue.size);
    queue.put(4);
    println!("{:?}", queue);
    queue.put(24);
    println!("{:?}", queue);
    println!("{:?}", queue.get());
    queue.put(7);
    println!("{:?}", queue);
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_get_gunction() {
        let mut q = Queue::<u8>::new(vec![1u8, 2u8], 2);
        assert_eq!(Some(1), q.get());
    }
}
