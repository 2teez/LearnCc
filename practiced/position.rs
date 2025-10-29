#![deny(clippy::all, clippy::pedantic, unused)]

#[derive(Debug)]
struct Point {
    x: f64,
    y: f64,
}

#[derive(Debug)]
struct Position {
    pt: Point,
}

impl Position {
    fn new(x: f64, y: f64) -> Self {
        Self { pt: Point { x, y } }
    }

    fn from_point(pt: Point) -> Self {
        Self { pt }
    }

    fn distance(&self) -> f64 {
        f64::sqrt(self.pt.x * self.pt.x + self.pt.y * self.pt.y)
    }
}

fn main() {
    let pt = Position::new(1.35f64, 0.125f64);
    println!("{:?}", pt.distance());

    let point = Point { x: 3.1, y: 0.67 };
    let pt2 = Position::from_point(point);
    println!("{:?}", pt2.distance());
}
