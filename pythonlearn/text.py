"""
name = "121"

stock_price = 19.1
stock_code = "003032"
stock_price_daily_growth_factor = 1.2
growth_days = 9
finally_stock_price = stock_price * stock_price_daily_growth_factor ** growth_days
setup = 'a duck goes into a bar ...'
print(f"公司:{name}, 股票代码:{stock_code}, 当前股价:{stock_code}")
print("每日增长系数：%0.1f,经过%d天后，股价增长达到了：%0.2f"
     %(stock_price_daily_growth_factor, growth_days, finally_stock_price))

#stock_code.replace('0', '*')
print(stock_code.replace('0', '*'))
#stock_code.strip('0')
print(stock_code.strip('0'))

setup.capitalize()
print(setup)
print(setup.capitalize())
print(setup.upper())
print(setup.lower())
print(setup.center(40))

sum = 0
i = 1
while i <= 100:
    sum += i
    i += 1
print(f"{sum}")
"""
"""
import random
num = random.randint(1, 100)


flag = True
while flag:
    guess_num = int(input("请输入猜的数字:"))
    if guess_num == num:
        print("猜对了")
        flag = False
    elif guess_num > num:
        print("猜大了")
    else:
        print("猜小了")

"""
#输出99乘法表
for i in range(1,10):
    for j in range(1,i+1):
        print(f"{j} * {i} = {j * i}\t", end='')
    print()
