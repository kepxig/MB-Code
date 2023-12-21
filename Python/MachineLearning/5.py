from efficient_apriori import apriori

# 给定数据集
transactions = [('A', 'C', 'D'), ('B', 'C', 'E'), ('A', 'B', 'C', 'E'), ('B', 'E')]

# 设置支持度和置信度的最小阈值
min_support = 0.5
min_confidence = 1

# 使用Efficient Apriori进行频繁项集和关联规则的挖掘
itemsets, rules = apriori(transactions, min_support=min_support, min_confidence=min_confidence)

# 打印频繁项集
print("频繁项集:")
for itemset in itemsets:
    print(itemset)

# 打印关联规则
print("\n关联规则:")
for rule in rules:
    print(rule)