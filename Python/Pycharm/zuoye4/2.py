def search(list1,list2):
    list_out=[]
    for i in list1:
        mark=1
        if i in list2:
            index_i=list2.index(i)
            for j in list2:
                if index_i+1>=(len(list2)):
                    mark=0
                    break
                else:
                    if list2[index_i+1]>i:
                        print('对于 num1 中的数字 %d ,第二个数组中数字%d右边的下一个较大数字是 %d 。'%(i,i,list2[index_i+1]))
                        list_out.append(list2[index_i+1])
                        break #找到
                    else:
                        index_i+=1
            if mark==0:
                list_out.append(-1)
                print('对于 num1 中的数字 %d ,第二个数组中没有下一个更大的数字，所以输出 -1 。'%i)
    print (list_out)
nums1=[4,1,2]
nums2=[1,3,4,2]
search(nums1,nums2)
nums1=[2,4]
nums2=[1,2,3,4]
search(nums1,nums2)