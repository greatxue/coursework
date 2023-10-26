#### Please do not use input() function!!!
class process_derivative(object):

    def __init__(self, polynominal):
        self.polynominal = polynominal

    def get_first_derivative(self):
        # You should follow the example format. Do not use input()
        poly = self.polynominal
        

        ## First: Is it a constant?
        if poly.isdigit() == True:
                result_two = "0"
                return "The first derivative is: " + result_two
        elif poly.isdigit() == False:
                if poly[0] == "-": pass
                else: poly = "+" + poly
                signNum = []
                sign = []
                splitted_term = []
                num = 0
                pre_num_code = 0
        ## Second: Split it by sign.
                for i in poly:
                    if i == "+":
                        sign.append("+")
                        signNum.append(num)
                    if i == "-":
                        sign.append("-")
                        signNum.append(num)                   
                    num = num + 1
                #print("signNum",signNum)###############
                #print("sign",sign)##############

                for num_code in signNum[1:]:
                    splitted_term.append(poly[pre_num_code+1 : num_code])
                    pre_num_code = num_code
                splitted_term.append(poly[num_code+1:])
                #print("splitted_term",splitted_term)##################

                #print("-------------")##############
                
                newSeperated = []
                for j in splitted_term:
                    #print("j",j)######################
                    if j.isdigit() == True or j[0] == "0": 
                        continue
                    elif j.isdigit() != True:
                        coefficient = j[:j.index("*")]
                        #print("coefficient",coefficient)##########################
                        try:    prime = j[j.index("^")+1:]
                        except: prime = "1"
                        #print("prime",prime)#################
                        
        ### Third: Operation of derivative.
                        coefficient = int(coefficient)
                        prime = int(prime)
                        coefficientNew = coefficient * prime
                        primeNew = prime - 1 
                        coefficientNew = str(coefficientNew)
                        primeNew = str(primeNew)
                        #print("primeNew",primeNew)#################

                        
        ### Fourth: New Combination.
                        if coefficient == "0":##modified
                            continue
                        elif primeNew == "0":
                            new_seperated = coefficientNew
                        elif primeNew == "1":
                            new_seperated = coefficientNew+"*"+j[j.index("*")+1:j.index("*")+2]
                        elif primeNew == "-1":
                            new_seperated = coefficientNew
                        elif primeNew != "0":
                            new_seperated = coefficientNew+"*"+j[j.index("*")+1:j.index("*")+2]+"^"+primeNew
                        

                    
                       
                    
                        #print("new_seperated",new_seperated)#############
                        #print("-------------")#########
                    
                        newSeperated.append(new_seperated)
                    #print("newSeparated",newSeperated)#########
                resultList = []
                num_2 = 0
                while num_2+1 <= len(newSeperated):
                    resultList.append(sign[num_2])
                    resultList.append(newSeperated[num_2])
                    num_2 = num_2 + 1
                    #print("resultListProcessing",resultList)############
                
                if "0" in resultList:
                    index =resultList.index("0")
                    resultList.pop(index)
                    resultList.pop(index-1)
                #print("resultList",resultList)############
                if resultList[0] == "+":
                    resultList.pop(0)
                
                
                result_two = "".join(resultList)
                #print("result_two",result_two)###########
                return "The first derivative is: " + result_two  # e.g. "The first derivative is: '6*x^2+6*x+5'"






