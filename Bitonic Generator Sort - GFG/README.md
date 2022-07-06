# Bitonic Generator Sort
## Easy 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">Given an array <strong>arr[]</strong> of <strong>N</strong> distinct numbers, the task is to sort all even-placed numbers in increasing and odd-place numbers in decreasing order. The modified array should contain all sorted even-placed numbers followed by reverse sorted odd-placed numbers.<br>
Note that the first element is considered as even because of its index 0.</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input: </strong>N = 8
arr[] = {0, 1, 2, 3, 4, 5, 6, 7}
<strong>Output:</strong> 0 2 4 6 7 5 3 1
<strong>Explanation</strong>: 
Even-place elements : 0, 2, 4, 6
Odd-place elements : 1, 3, 5, 7
Even-place elements in increasing order : 
0, 2, 4, 6
Odd-Place elements in decreasing order : 
7, 5, 3, 1</span></pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input: </strong>N = 9
arr[] = {3, 1, 2, 4, 5, 9, 13, 14, 12}
<strong>Output:</strong> 2 3 5 12 13 14 9 4 1
<strong>Explanation</strong>: 
Even-place elements : 3, 2, 5, 13, 12
Odd-place elements : 1, 4, 9, 14
Even-place elements in increasing order : 
2, 3, 5, 12, 13
Odd-Place elements in decreasing order : 
14, 9, 4, 1</span></pre>

<p><br>
<span style="font-size:18px"><strong>Your Task:</strong><br>
This is a function problem. You don't need to take any input, as it is already accomplished by the driver code. You just need to complete the function <strong>bitonicGenerator</strong>() that takes array<strong> arr </strong>and integer<strong> N</strong>&nbsp;as parameters and modify the array according to the above condition.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(NlogN).<br>
<strong>Expected Auxiliary Space:</strong> O(N).</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ N ≤ 10<sup>5</sup></span></p>
 <p></p>
            </div>