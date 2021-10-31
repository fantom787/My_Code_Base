letter = '''Dear <|NAME|> 
You Are Selected ! 
<|DATE|>'''
name = input("Entre Your Name\n")
date = input("Entre Date\n")
letter = letter.replace("<|NAME|>",name)
letter = letter.replace("<|DATE|>",date)
print(letter)