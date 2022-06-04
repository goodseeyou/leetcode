import math
class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        _max = 0
        for p1_idx in range(len(points)-1):
            slopes = {}
            for p2_idx in range(p1_idx+1, len(points)):
                
                slope = math.inf
                if points[p1_idx][1] != points[p2_idx][1]:
                    slope = (points[p1_idx][0] - points[p2_idx][0]) / (points[p1_idx][1] - points[p2_idx][1])
                if slope not in slopes:
                    slopes[slope] = 1
                else:
                    slopes[slope] += 1
                _max = max(slopes[slope], _max)
            
        return _max+1
