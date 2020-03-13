#objective is to count groups formed to make sum of 3

n=int(input("Enter the number of bags: "))

bags=list(map(float,input().split()))

#O(nlogn)
bags.sort()

print(bags)

#sum of immediate bags
left_index=0
diff_current=3.00-bags[left_index]


#group counter
count=0

for i in range(n-1,-1,-1):
	if bags[i]>diff_current:
		count+=1
	elif bags[i]<=diff_current:
		if bags[i]+bags[left_index]<=3.0:
			left_index=left_index+1
			diff_current=3.00-bags[left_index]
		count+=1
	if left_index>=i:
		break


print(count)
