# Operation-System
下面是我在学习操作系统中写的一些操作系统常用算法  <br>
写于2018年 大二上学期  我对它们进行了整理  <br>
通过敲完这些算法 会让你更理解操作系统的原理 <br>
使用 VC6.0 和 CB环境都行 <br>
纯C语言编写  <br>

<img src="img/01.PNG"/>
###银行家算法自然语言描述：<br>
设 Requesti是进程 Pi的请求向量，如果 Requesti［j］=K，表示进程 Pi需要 K 个 Rj类型<br>
的资源。当 Pi发出资源请求后，系统按下述步骤进行检查：<br>
(1) 如果 Requesti［j］≤Need［i,j］，便转向步骤 2；否则认为出错，因为它所需要的资源数<br>
已超过它所宣布的最大值。
(2) 如果 Requesti［j］≤Available［j］，便转向步骤(3)；否则， 表示尚无足够资源，Pi 须等
待。<br>
(3) 系统试探着把资源分配给进程 Pi，并修改下面数据结构中的数值：<br>
Available［j］=Available［j］-Requesti［j］;<br>
Allocation［i,j］=Allocation［i,j］+Requesti［j］;<br>
Need［i,j］=Need［i,j］-Requesti［j］;<br>
(4) 系统执行安全性算法，检查此次资源分配后，系统是否处于安全状态。若安全，才正式<br>
将资源分配给进程 Pi，以完成本次分配；否则， 将本次的试探分配作废，恢复原来的<br>
资源分配状态，让进程 Pi等待。<br/>

<img src="img/02.PNG">

<br>
安全性算法自然语言描述：<br>
(1) 设置两个向量：① 工作向量 Work: 它表示系统可提供给进程继续运行所需的各类资源<br>
数目，它含有 m 个元素，在执行安全算法开始时，Work∶=Available; ② Finish: 它表示<br>
系统是否有足够的资源分配给进程，使之运行完成。开始时先做 Finish［i］∶=false; 当<br>
有足够资源分配给进程时， 再令 Finish［i］∶=true。<br>
(2) 从进程集合中找到一个能满足下述条件的进程：<br>
① Finish［i］=false; ② Need［i,j］≤Work［j］； 若找到， 执行步骤(3)， 否则，执行<br>
步骤(4)<br>
(3) 当进程 Pi 获得资源后，可顺利执行，直至完成，并释放出分配给它的资源，故应执行：<br>
Work［j］∶ ［i］+Allocation［i,j］<br>
Finish［i］∶<br>
go to step (2);<br>
(4) 如果所有进程的 Finish［i］=true 都满足， 则表示系统处于安全状态；否则，系统处于<br>
不安全状态。<br>


