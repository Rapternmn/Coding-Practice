


dict_roman = {}

dict_roman['I'] = 1
dict_roman['V'] = 5
dict_roman['X'] = 10

str_roman = 'III'

count = 0


for a in str_roman:
	count += dict_roman[a]


for i in range(len(str_roman) - 1):

	curr_val = dict_roman[str_roman[i]]

	next_val = dict_roman[str_roman[i+1]]

	if str_roman[i] == str_roman[i+1]:
		count += curr_val

	elif (next_val > curr_val):
		count = count - curr_val

	else:
		count += curr_val



count += dict_roman[len(str_roman) - 1 ]