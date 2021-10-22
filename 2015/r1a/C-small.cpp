#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

#define D(x) 

const int MAX_N = 20;
const int INF = 0x3f3f3f3f;
#define zero(x) (((x)>0?(x):-(x))<eps)
#define eps 1.0E-8
#define MAX_POINT_NUM 0

int double_cmp(double a)
{
	if (zero(a))
		return 0;
	return a > 0 ? 1 : -1;
}

struct Point
{
	double	x,y;
	Point()
	{}
	Point(double x, double y):x(x), y(y)
	{}
	Point operator - (Point &a)
	{
		return Point(x - a.x, y - a.y);
	}	
	bool operator <(const Point &a)const
	{
	    return atan2(y, x) < atan2(a.y, a.x);
	}
	bool operator == (const Point &a) const
	{
		return x == a.x && y == a.y;
	}
};

double cross_product(Point a, Point b)
{
	return a.x * b.y - b.x * a.y;
}

double cross_product(Point p0, Point p1, Point p2)
{
	return cross_product(p1 - p0, p2 - p0);
}

double dot_product(Point a, Point b)
{
	return a.x * b.x + a.y * b.y;
}

double dot_product(Point p0, Point p1, Point p2)
{
	return dot_product(p1 - p0, p2 - p0);
}

double point_dist(Point a)
{
	return sqrt(a.x * a.x + a.y * a.y);
}

double point_dist(Point a, Point b)
{
	return point_dist(a - b);
}

struct Line
{
	Point a, b;
	Line()
	{}
	Line(Point a, Point b):a(a), b(b)
	{}	
	bool operator == (const Line &l) const
	{
		return l.a == a && l.b == b;
	}
};

bool points_inline(Point p1, Point p2, Point p3)
{
	return zero(cross_product(p1, p2, p3));
}

bool same_side(Point p1, Point p2, Line l)
{
	return double_cmp(cross_product(l.a, p1, l.b) * cross_product(l.a, p2, l.b)) > 0;
}

bool point_online_inclusive(Point p, Line l)
{
	return zero(cross_product(p, l.a, l.b)) && double_cmp(dot_product(p, l.a, l.b)) <= 0;
}

bool point_online_exclusive(Point p, Line l)
{
	return zero(cross_product(p, l.a, l.b)) && double_cmp(dot_product(p, l.a, l.b)) < 0;
}

bool overlap_exclusive(Line u, Line v)
{
	if (u == v || (u.a == v.b && u.b == v.a))
		return true;
	if (!points_inline(u.a, u.b, v.a) || !points_inline(u.a, u.b, v.b))
		return false;
	bool ret = point_online_exclusive(u.a, v);
	ret = ret || point_online_exclusive(u.b, v);
	ret = ret || point_online_exclusive(v.a, u);
	ret = ret || point_online_exclusive(v.b, u);
	return ret;
}

bool intersect_inclusive(Line u, Line v)
{
	if (!points_inline(u.a, u.b, v.a) || !points_inline(u.a, u.b, v.b))
		return !same_side(u.a, u.b, v) && !same_side(v.a, v.b, u);
	bool ret = point_online_inclusive(u.a, v);
	ret = ret || point_online_inclusive(u.b, v);
	ret = ret || point_online_inclusive(v.a, u);
	ret = ret || point_online_inclusive(v.b, u);
	return ret;
}

double line_length(Line l)
{
	return point_dist(l.a - l.b);
}

double point_line_dist(Point a, Line l)
{
	return abs(cross_product(l.a - a, l.b - a) / line_length(l));
}

Point intersection_point(Line l1,Line l2)
{
    double s1 = cross_product(l1.a, l1.b, l2.a);
    double s2 = cross_product(l1.a, l1.b, l2.b);
    Point ret;
    ret.x = (s1 * l2.b.x - s2 * l2.a.x) / (s1 - s2);
    ret.y = (s1 * l2.b.y - s2 * l2.a.y) / (s1 - s2);
    return ret;
}

struct Polygon
{
	Point point[MAX_POINT_NUM];
	int point_num;
};

bool is_convex(Polygon &a) //point should be counter-clockwise
{
	for (int i = 0; i < a.point_num; i++)
	{
		Point p1 = a.point[(i + 1) % a.point_num] - a.point[i];
		Point p2 = a.point[(i + 2) % a.point_num] - a.point[(i + 1) % a.point_num];
		if (double_cmp(cross_product(p1, p2)) < 0)
			return false;
	}
	return true;
}

bool point_in_convex(Polygon &a, Point peg) //point should be counter-clockwise
{
	for (int i = 0; i < a.point_num; i++)
	{
		Point p1 = a.point[(i + 1) % a.point_num] - a.point[i];
		Point p2 = peg - a.point[(i + 1) % a.point_num];
		if (double_cmp(cross_product(p1, p2)) <= 0)
			return false;
	}
	return true;
}

bool graham_cmp(const Point &a, const Point &b)
{
	return a.y < b.y || (a.y == b.y && a.x < b.x);
}

bool graham_ok(Point &a, Point &b, Point &c)
{
	return double_cmp(cross_product(a, b, c)) >= 0;
}

int graham(Point point[], int n, Point ret[]){
	int top = 0;
	sort(point, point + n, graham_cmp);
	for (int i = 0; i < 2; i++)
		ret[top++] = point[i];

	if (n <= 2)
		return n;

	for (int i = 2; i < n; i++)
	{
		while (top >= 2 && graham_ok(ret[top - 1], ret[top - 2], point[i]))
			top--;
		ret[top++] = point[i];
	}
	int len = top;
	ret[top++] = point[n - 2];
	for (int i = n - 3; i >= 0; i--)
	{
		while (top > len && graham_ok(ret[top - 1], ret[top - 2], point[i]))
			top--;
		ret[top++] = point[i];
	}
	return top;
}

Point pnt[MAX_N];
int ans[MAX_N];
int n;
int convex_num;
Point res[MAX_N];

bool on_convex(Point a)
{
	for (int i = 0; i < convex_num; i++)
		if (res[i].x == a.x && res[i].y == a.y)
			return true;
	for (int i = 0; i < convex_num; i++)
	{
		Point p1 = res[i];
		Point p2 = res[(i + 1) % convex_num];
		D(printf("%.2f %.2f %.2f\n", p1.y, p2.y, a.y));
		if (point_online_inclusive(a, Line(p1, p2)))
			return true;
	}
	return false;
}

void update(int bits, int num)
{
	int j = 0;
	while (bits > 0)
	{
		if (bits & 1 && on_convex(pnt[j]))
		{
			ans[j] = min(ans[j], num);
		}
		bits >>= 1;
		j++;
	}
}

void output()
{
	for (int i = 0; i < n; i++)
	{
		printf("%d\n", ans[i]);
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	int case_num = 0;
	while (t--)
	{
		case_num++;
		printf("Case #%d:\n", case_num);
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%lf%lf", &pnt[i].x, &pnt[i].y);
		}
		for (int i = 0; i < n; i++)
			ans[i] = INF;
		for (int i = 0; i < (1 << n); i++)
		{
			Point temp[MAX_N];
			int top = 0;
			int bits = i;
			int j = 0;
			while (bits > 0)
			{
				if (bits & 1)
					temp[top++] = pnt[j];
				bits >>= 1;
				j++;
			}
			D(printf("**%d\n", top));
			convex_num = graham(temp, top, res);
			update(i, n - top);
		}
		output();
	}
	return 0;
}
