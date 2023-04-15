0	:	beginclass test5 
1	:	beginfunc sum
2	:	a = popparam
3	:	ans=0
4	:	i=0
5	:	if i<30 goto 7
6	:	goto 21
7	:	j=0
8	:	if j<30 goto 10
9	:	goto 19
10	:	t0=w2*4
11	:	t1=i*int t0
12	:	t2=j*int 4
13	:	t3=t1+int t2
14	:	t4=a[t3]
15	:	t5=ans+int t4
16	:	ans=t5
17	:	j=j+int 1
18	:	goto 8
19	:	i=i+int 1
20	:	goto 5
21	:	return ans
22	:	endfunc 
23	:	beginfunc main
24	:	i=0
25	:	if i<30 goto 27
26	:	goto 40
27	:	j=0
28	:	if j<30 goto 30
29	:	goto 38
30	:	t6=30*4
31	:	t7=i*int t6
32	:	t8=j*int 4
33	:	t9=t7+int t8
34	:	t10=i*int j
35	:	*(arr+int t9)=t10
36	:	j=j+int 1
37	:	goto 28
38	:	i=i+int 1
39	:	goto 25
40	:	pushparam arr
41	:	stackpointer=stackpointer+int 8
42	:	t11=call sum, 1
43	:	stackpointer=stackpointer-int8
44	:	u=t11
45	:	u=u+int 1
46	:	if u>5 goto 48
47	:	goto 51
48	:	return u
49	:	u=u-int 1
50	:	goto 68
51	:	if u<4 goto 53
52	:	goto 57
53	:	u=u-int 1
54	:	return u
55	:	u=u+int 1
56	:	goto 68
57	:	if u==10 goto 59
58	:	goto 62
59	:	t12=u+int 4
60	:	return t12
61	:	goto 68
62	:	t13=30*4
63	:	t14=0*int t13
64	:	t15=0*int 4
65	:	t16=t14+int t15
66	:	t17=arr[t16]
67	:	return t17
68	:	return 0
69	:	endfunc 
70	:	endclass 
