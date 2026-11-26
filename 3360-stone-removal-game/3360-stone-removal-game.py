class Solution:
    def canAliceWin(self, n: int) -> bool:
        if(n<10):
            return False
        turn=10
        alice=True
        while(n>=turn):
            n-=turn
            turn=turn-1
            alice=not alice
        return not alice