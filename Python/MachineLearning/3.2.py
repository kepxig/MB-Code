from sklearn.datasets import load_iris
from sklearn.tree import DecisionTreeClassifier
from sklearn.model_selection import train_test_split

# 加载鸢尾花数据集
iris = load_iris()
X = iris.data
y = iris.target

# 设置树的最大深度为4
clf = DecisionTreeClassifier(max_depth=4)

# 随机划分数据集为训练集和测试集
N = 100  # 你可以自行设置训练集的大小
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=150 - N, random_state=42)

# 训练模型
clf.fit(X_train, y_train)

# 可视化决策树模型（需要安装graphviz）
from sklearn.tree import export_text
tree_rules = export_text(clf, feature_names=iris.feature_names)
print("决策树模型规则:\n", tree_rules)

# 预测测试数据
y_pred = clf.predict(X_test)

# 计算准确率
accuracy = (y_pred == y_test).mean()
print("分类预测的准确率:", accuracy)