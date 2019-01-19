import java.util.*;

public class q149 {
    public static void main(String[] args) {
        Map<Line, HashSet<Point>> lines = new HashMap<>();
        ArrayList<Point> points = new ArrayList<>();

        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int ans = 2;

        for (int i = 0; i < N; i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();

            points.add(new Point(x,y));
        }

        for (Point p : points) {
            System.out.println(p);
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i != j) {
                    Point p1 = points.get(i);
                    Point p2 = points.get(j);
                    Line l = new Line(p1, p2);
    
                    System.out.println(l);
                    
                    if (lines.containsKey(l)) {
                        System.out.println("Já existe!");
                        
                        HashSet<Point> hs = lines.get(l);

                        if (!hs.contains(p1)) hs.add(p1);
                        if (!hs.contains(p2)) hs.add(p2);
                    } else {
                        System.out.println("Não existe ainda...");
                        
                        HashSet<Point> pts  = new HashSet<>();
                        pts.add(p1);
                        pts.add(p2);
                        
                        lines.put(l,pts);
                    }
                    
                    System.out.println(lines.get(l));
    
                    if (lines.get(l).size() > ans) ans = lines.get(l).size();
                }
            }
        }

        System.out.println(ans);
        String.
    }
}

/*

class Solution {
    private class Line {
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
    
    public int maxPoints(Point[] points) {
        Map<Line, HashSet<Point>> lines = new HashMap<>();
    
        int ans;
        
        if (points.length == 0) {
            ans = 0;
        } else if (points.length == 1) {
            ans = 1;
        } else {
            ans = 2;
        
            for (int i = 0; i < points.length; i++) {
                for (int j = 0; j < points.length; j++) {
                    if (i != j) {
                        Point p1 = points[i];
                        Point p2 = points[j];
                        Line l = new Line(p1, p2);

                        if (lines.containsKey(l)) {                       

                            lines.get(l).add(p1);
                            lines.get(l).add(p2);
                        } else {
                            HashSet<Point> pts  = new HashSet<>();

                            pts.add(p1);
                            pts.add(p2);
                            lines.put(l,pts);
                        }

                        if (lines.get(l).size() > ans) ans = lines.get(l).size();
                    }
                }
            }
        }
        
        return ans;
    }
}



------------------------------------------------

// Remover duplicatas e armazenar quantidades
        Map<MyPoint, Integer> allPoints = new HashMap<>();
        ArrayList<MyPoints> arr = new ArrayList<>();
        
        for (Point p : points) {
            MyPoint p = new MyPoint(p.x, p.y);
            
            if (allPoints.containsKey(p)) {
                allPoints.replace(p, allPoints.get(p)+1);
            } else {
                allPoints.put(p,1);
                arr.add(p);
            }
        }
                
        // Percorrer os pontos e montar as linhas
        
        Map<Line, HashSet<MyPoint>> lines = new HashMap<>();
                
        int ans;
        
        if (points.length == 0) {
            ans = 0;
        } else if (points.length == 1) {
            ans = 1;
        } else {
            ans = 2;
        
            for (int i = 0; i < points.length; i++) {
                for (int j = 0; j < points.length; j++) {
                    if (i != j) {
                        Point p1 = points[i];
                        Point p2 = points[j];
                        Line l = new Line(p1, p2);

                        if (lines.containsKey(l)) {                       

                            //lines.get(l).add(p1);
                            //lines.get(l).add(p2);
                            
                            lines.get(l).add(p1.x+","+p1.y);
                            lines.get(l).add(p2.x+","+p2.y);
                            
                        } else {
                            HashSet<String> pts  = new HashSet<>();

                            pts.add(p1.x+","+p1.y);
                            pts.add(p2.x+","+p2.y);
                            lines.put(l,pts);
                        }

                        if (lines.get(l).size() > ans) ans = lines.get(l).size();
                    }
                }
            }
        }
        
        return ans;
 */


