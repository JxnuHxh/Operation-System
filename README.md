# Operation-System
下面是我在学习操作系统中写的一些操作系统常用算法  <br>
写于2018年 大二上学期  我对它们进行了整理  <br>
通过敲完这些算法 会让你更理解操作系统的原理 <br>
使用 VC6.0 和 CB环境都行 <br>
纯C语言编写  <br>

<img src="img/01.PNG"/>
###银行家算法自然语言描述：
设 Requesti是进程 Pi的请求向量，如果 Requesti［j］=K，表示进程 Pi需要 K 个 Rj类型
的资源。当 Pi发出资源请求后，系统按下述步骤进行检查：
(1) 如果 Requesti［j］≤Need［i,j］，便转向步骤 2；否则认为出错，因为它所需要的资源数
已超过它所宣布的最大值。
(2) 如果 Requesti［j］≤Available［j］，便转向步骤(3)；否则， 表示尚无足够资源，Pi 须等
待。
(3) 系统试探着把资源分配给进程 Pi，并修改下面数据结构中的数值：
Available［j］=Available［j］-Requesti［j］;
Allocation［i,j］=Allocation［i,j］+Requesti［j］;
Need［i,j］=Need［i,j］-Requesti［j］;
(4) 系统执行安全性算法，检查此次资源分配后，系统是否处于安全状态。若安全，才正式
将资源分配给进程 Pi，以完成本次分配；否则， 将本次的试探分配作废，恢复原来的
资源分配状态，让进程 Pi等待。

