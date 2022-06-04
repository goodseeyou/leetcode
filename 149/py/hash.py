class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        lines = {}
        len_p = len(points)
        max_c = 1
        for i in range(len_p):
            for j in range(i+1, len_p):
                line = self.get_line(points[i], points[j])
                lines[line] = lines.get(line, 0)+1
                if lines[line] > max_c:
                    max_c = lines[line]
                print(line, lines[line])

        return (1+(1 + 8*max_c)**0.5)/2

    def get_line(self, p1: List[int], p2: List[int]):
        xdiff = p1[0] - p2[0]
        if xdiff == 0:
            m = 'INF'
            b = p1[1]
        else:
            m = (p1[1] - p2[1]) / xdiff
            b = p1[1] - m * p1[0]

        return (m, b)
