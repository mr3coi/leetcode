class Solution {
public:
    using Point = vector<int>;

    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    double largestTriangleArea(vector<Point> const& points) {
        double ret{-1.0};
        for (int i = 0; i < points.size() - 2; ++i)
        {
            for (int j = i + 1; j < points.size() - 1; ++j)
            {
                for (int k = j + 1; k < points.size(); ++k)
                {
                    if (isOnALine(points[i], points[j], points[k]))
                    {
                        continue;
                    }
                    ret = std::max(ret, triangleArea(points[i], points[j], points[k]));
                }
            }
        }
        return ret;
    }

    double triangleArea(Point const& p1, Point const& p2, Point const& p3)
    {
        double ret = p1[0] * p2[1] + p2[0] * p3[1] + p3[0] * p1[1];
        ret -= p1[1] * p2[0] + p2[1] * p3[0] + p3[1] * p1[0];
        return std::abs(ret) / 2;
    }

    bool isOnALine(Point const& p1, Point const& p2, Point const& p3)
    {
        return (p1[1] - p2[1]) * (p2[0] - p3[0]) == (p2[1] - p3[1]) * (p1[0] - p2[0]);
    }
};
