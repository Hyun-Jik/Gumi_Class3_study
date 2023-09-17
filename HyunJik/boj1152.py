# sentence = input()
# cnt = 1 # 마지막에 단어 끝나고 나선 갯수를 하나 더 해줘야하기에
# for i in sentence:
#     if i ==' ':
#        cnt +=1
# print(cnt)

sentence = list(map(str,input().split())) # 각각의 단어들을 split해준다
print(len(sentence))