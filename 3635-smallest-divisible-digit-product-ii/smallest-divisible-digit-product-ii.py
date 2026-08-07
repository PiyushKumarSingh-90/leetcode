from collections import deque

class Solution:
    def smallestNumber(self, num: str, t: int) -> str:
        e2 = e3 = e5 = e7 = 0
        tt = t
        while tt % 2 == 0:
            e2 += 1; tt //= 2
        while tt % 3 == 0:
            e3 += 1; tt //= 3
        while tt % 5 == 0:
            e5 += 1; tt //= 5
        while tt % 7 == 0:
            e7 += 1; tt //= 7
        
        if tt != 1:
            return "-1"
            
        n = len(num)
        
        def get_exp(d, p):
            c = 0
            while d > 0 and d % p == 0:
                c += 1
                d //= p
            return c
            
        dE = [(0,0,0,0)]*10
        for d in range(1, 10):
            dE[d] = (get_exp(d,2), get_exp(d,3), get_exp(d,5), get_exp(d,7))
            
        CAP2, CAP3, CAP5, CAP7 = e2, e3, e5, e7
        D2, D3, D5, D7 = CAP2+1, CAP3+1, CAP5+1, CAP7+1
        size = D2 * D3 * D5 * D7
        
        def idx(a,b,c,d):
            return ((a*D3 + b)*D5 + c)*D7 + d
            
        dist = [-1] * size
        start = idx(0,0,0,0)
        dist[start] = 0
        q = deque([(0,0,0,0)])
        
        while q:
            r2,r3,r5,r7 = q.popleft()
            cur = dist[idx(r2,r3,r5,r7)]
            for d in range(1,10):
                a,b,c,e = dE[d]
                nr2 = min(CAP2, r2+a)
                nr3 = min(CAP3, r3+b)
                nr5 = min(CAP5, r5+c)
                nr7 = min(CAP7, r7+e)
                ii = idx(nr2,nr3,nr5,nr7)
                if dist[ii] == -1:
                    dist[ii] = cur+1
                    q.append((nr2,nr3,nr5,nr7))
                    
        min_total_needed = dist[idx(CAP2,CAP3,CAP5,CAP7)]
        
        def needed(r2, r3, r5, r7):
            r2 = min(max(0,r2), CAP2)
            r3 = min(max(0,r3), CAP3)
            r5 = min(max(0,r5), CAP5)
            r7 = min(max(0,r7), CAP7)
            return dist[idx(r2,r3,r5,r7)]
            
        orig = [int(c) for c in num]
        
        def check(digs):
            E2 = E3 = E5 = E7 = 0
            for d in digs:
                if d == 0:
                    return False
                a,b,c,e = dE[d]
                E2+=a; E3+=b; E5+=c; E7+=e
            return E2>=e2 and E3>=e3 and E5>=e5 and E7>=e7
            
        if check(orig):
            return num
            
        pre2=[0]*(n+1); pre3=[0]*(n+1); pre5=[0]*(n+1); pre7=[0]*(n+1)
        for i in range(n):
            d = orig[i]
            a,b,c,e = dE[d] if d!=0 else (0,0,0,0)
            pre2[i+1] = pre2[i]+a
            pre3[i+1] = pre3[i]+b
            pre5[i+1] = pre5[i]+c
            pre7[i+1] = pre7[i]+e
            
        def build_suffix(L, r2, r3, r5, r7):
            res = []
            rem2,rem3,rem5,rem7 = max(0,r2),max(0,r3),max(0,r5),max(0,r7)
            for pos in range(L):
                remaining_after = L-pos-1
                for d in range(1,10):
                    a,b,c,e = dE[d]
                    nr2 = rem2-a if rem2-a>0 else 0
                    nr3 = rem3-b if rem3-b>0 else 0
                    nr5 = rem5-c if rem5-c>0 else 0
                    nr7 = rem7-e if rem7-e>0 else 0
                    if needed(nr2,nr3,nr5,nr7) <= remaining_after:
                        res.append(str(d))
                        rem2,rem3,rem5,rem7 = nr2,nr3,nr5,nr7
                        break
            return "".join(res)
        
        # 1. Find the first occurrence of '0'.
        first_zero = n
        for i in range(n):
            if orig[i] == 0:
                first_zero = i
                break
                
        # 2. Bound the loop to prevent trying to attach suffixes to invalid prefixes
        for i in range(min(n-1, first_zero), -1, -1):
            for d in range(orig[i]+1, 10):
                a,b,c,e = dE[d]
                r2 = e2-(pre2[i]+a)
                r3 = e3-(pre3[i]+b)
                r5 = e5-(pre5[i]+c)
                r7 = e7-(pre7[i]+e)
                L = n-1-i
                
                # 3. Quick O(1) mathematical check overrides the slow O(L) builder test
                if needed(r2,r3,r5,r7) <= L:
                    suf = build_suffix(L,r2,r3,r5,r7)
                    prefix = "".join(str(x) for x in orig[:i])
                    return prefix + str(d) + suf

        # Need to increase length beyond n
        L = max(n+1, min_total_needed)
        return build_suffix(L, e2, e3, e5, e7)