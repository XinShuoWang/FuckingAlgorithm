from datetime import *


class Solution:
    def dayOfTheWeek(self, day: int, month: int, year: int) -> str:
        d1 = datetime(year, month, day)
        ans = ["Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"]
        return ans[d1.isoweekday() - 1]
