import math


def vertical(start, end, inc):
	temp = []
	end = -end if(inc < 0) else end
	for i in range(start[1] + inc, start[1] + end + inc, inc):
		temp.append((start[0], i))
	return temp

def horizontal(start, end, inc):
	temp = []
	end = -end if(inc < 0) else end
	for i in range(start[0] + inc, start[0] + end + inc, inc):
		temp.append((i, start[1]))
	return temp	
	

def parse(vec):
	x, y = 0, 0
	temp = []
	for i in vec:
		xi = 1 if (i[0] == 'R') else -1 if (i[0] == 'L') else 0
		yi = 1 if (i[0] == 'U') else -1 if (i[0] == 'D') else 0
		
		num = int(i[1:])
		
		if(xi != 0):
			temp.extend( horizontal((x, y), num, xi))
			x = x + (num * xi)
		elif(yi != 0):
			temp.extend( vertical((x, y), num, yi))
			y = y + (num * yi)
		
	return temp

def dist_euclidean(point):
	return math.sqrt(point[0] * point[0] + point[1] * point[1])

if __name__ == '__main__':
	line1 = input()
	line2 = input()

	line1v = line1.split(',')
	line2v = line2.split(',')
	
	line1s = set(parse(line1v))
	line2s = set(parse(line2v))
	
	intr = line1s.intersection(line2s)
	
	min_point = list(intr)[0]
	min_len = dist_euclidean(min_point);
	
	for i in intr:
		dist = dist_euclidean(i)
		if(min_len > dist):
			min_len = dist
			min_point = i
	
	print(abs(min_point[0]) + abs(min_point[1]))
