use "/Users/kevinshuey/Github/Assignments/cuhksz_ECO3121/as1/aghousehold.dta"
gen yield=d32/d31
sum yield c10 c13

reg yield c10
predict yield_hat1, xb
gen residual1=yield-yield_hat1

reg yield c13
predict yield_hat2, xb
gen residual2=yield-yield_hat2

egen res1_total=total(residual1)
egen res2_total=total(residual2)

gen rent_in_prop=c10/d31*100
gen rent_out_prop=c13/d31*100

reg yield rent_in_prop
reg yield rent_out_prop

gen log_yield=log(yield)
reg log_yield rent_in_prop
reg log_yield rent_out_prop
