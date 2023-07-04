import sympy as sp

n = sp.Symbol('n',integer=True)

# # 3.52700047185295
# print(sp.summation(sp.ntheory.divisor_sigma(n,1)/sp.factorial(n),(n,1,1000)).evalf())

# # 6.34009666889217
# print(sp.summation(sp.ntheory.divisor_sigma(n,2)/sp.factorial(n),(n,1,1000)).evalf())

# # 14.6935328472693
# print(sp.summation(sp.ntheory.divisor_sigma(n,3)/sp.factorial(n),(n,1,1000)).evalf())

# # 42.3010475037335
# print(sp.summation(sp.ntheory.divisor_sigma(n,4)/sp.factorial(n),(n,1,1000)).evalf())

# # 1.95408535787601
# print(sp.summation(sp.ntheory.totient(n)/sp.factorial(n),(n,1,1000)).evalf())

p = 22

# print(p/(p+1)+1/(p+2)+1/((p+1)*(p+3))+1/((p+1)*(p+2)*(p+4))+1/((p+1)*(p+2)*(p+3)*(p+5))+1/((p+1)*(p+2)*(p+3)*(p+4)*(p+6))+(1/((p+1)*(p+2)*(p+3)*(p+4)*(p+5)*(p+7))))

f = sp.factorial(p)/sp.factorial(p+n)*(p+n-1)

print(sp.summation(f,(n,1,10)).evalf())