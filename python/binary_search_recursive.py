

def binarySearch(array, start, end, needle):
	if start > end:
		return -1
	mid = (start + end)/2;
	if array[mid] == needle:
		return mid
	if needle < array[mid]:
		end = mid-1
	else:
		start = mid+1
	return binarySearch(array, start, end, needle)

array = [2, 3, 14, 25, 36, 47];

start = 0
end = len(array) - 1
needle = 13
index = binarySearch(array, start, end, needle);

if index != -1:
	print str(index) + ' ' + str(array[index])
print 'Not found: ' + str(index)