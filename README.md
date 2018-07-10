# codingame部分解题思路记录  
﻿>﻿>https://www.codingame.com  
这个网站最大的亮点应该是图形化界面。  
感觉这种直观的方式比较适合编程入门，以及增加对一些复杂的结构的理解，最主要的是图。  
像图论的知识在游戏的各种寻路中应用还是蛮多的，但是在学习的时候很难直接的判断自己的代码的问题。  
此外它的测试点不坑基本上样例过得去都能过去，然后时限不严格（还没有遇到过超时的问题）。  


# medium
# skynet-revolution-episode-1  
这里我是在与virus相连的所有link中找到任意一个exit距离最近的，这样能过测试点。  

但是想了一想感觉应该是求到（必死的结点）的距离  

比如完全二叉树的根节点就是一个这样的结点  
![这里写图片描述](https://img-blog.csdn.net/201804021026547?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2JpcmR5Xw==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)  

应该求到下述两个顶点的距离而不是到出口（叉叉处）的距离  
![这里写图片描述](https://img-blog.csdn.net/20180402102706396?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2JpcmR5Xw==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)  

不过并没有这么坑的测试点……  

# hard
## the-labyrinth
这题题目写到了A*……但是它哪里能用启发式搜索啊……测试点很严格，还是直接BFS求最优解吧……  
然后还有很奇怪的一点是计时是从到达控制台才开始，所以在到达C点之前要尽可能的探索完整个地图。

