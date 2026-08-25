<h2><a href="https://www.geeksforgeeks.org/problems/shopkeeper-profit/1">Shopkeeper Profit</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p><span style="font-size: 14pt;">Given an array <strong>arr[]</strong>, where arr[i] represents the price of the i-th product, calculate the total profit as follows:</span></p>
<p><span style="font-size: 14pt;">For each product, find the <strong>first</strong> product to its right whose price is greater than or equal to the current product's price. If such a product exists, the profit for the current product is the difference between their prices. Otherwise, the profit is equal to the current product's price.</span></p>
<p><span style="font-size: 14pt;">Return the total profit obtained by summing the profit for all products.</span></p>
<p><span style="font-size: 14pt;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 14pt;"><strong>Input: </strong>arr[] = [5, 4, 6, 2, 1]
<strong>Output: </strong>12<br><strong>Explanation:<br></strong>For 5, the first greater or equal price is 6, profit = 6 - 5 = 1
For 4, the first greater or equal price is 6, profit = 6 - 4 = 2
For 6, there is no greater or equal price to its right, profit = 6
For 2, there is no greater or equal price to its right, profit = 2
For 1, there is no greater or equal price to its right, profit = 1
Total profit = 1 + 2 + 6 + 2 + 1 = 12.</span></pre>
<pre><span style="font-size: 14pt;"><strong>Input: </strong>arr[] = [1, 2, 3, 4]
<strong>Output: </strong>7<br><strong>Explanation: <br></strong>For 1, the first greater or equal price to its right is 2, profit = 2 - 1 = 1
For 2, the first greater or equal price to its right is 3, profit = 3 - 2 = 1
For 3, the first greater or equal price to its right is 4, profit = 4 - 3 = 1
For 4, there is no greater or equal price to its right, profit = 4
Total profit = 1 + 1 + 1 + 4 = 7.</span></pre></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Stack</code>&nbsp;<code>STL</code>&nbsp;