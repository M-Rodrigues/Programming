import java.util.Objects;

public class Line {
    public double a;
    public double b;
    public double c;

    public Line(Point p1, Point p2) {
        a = p1.y - p2.y;
        b = p1.x - p2.x;
        c = p1.x*p2.y - p2.x*p1.y; 
        

        if (a < 0) { a *= -1; b *= -1; c *= -1; }
        if (a == 0 && b < 0) { a *= -1; b *= -1; c *= -1; }

        if (a == 0) {
            c /= b; 
            b = 1;
        } else {
            b /= a;
            c /= a;
            a = 1;
        }
    }

    @Override
    public String toString() {
        return a + "X " + (b > 0 ? "+" : "") + b + "Y " + (c > 0 ? "+" : "") + c + " = 0";
    }

    @Override
    public boolean equals(Object o) {
        if (o == this) return true;
        if (!(o instanceof Line)) {
            return false;
        }

        Line l = (Line) o;

        return 
            (Double.compare(a, l.a) == 0) 
            && (Double.compare(b, l.b) == 0)
            && (Double.compare(c, l.c) == 0);
    }

    @Override
    public int hashCode() {
        return Objects.hash(a,b,c);
    }
}