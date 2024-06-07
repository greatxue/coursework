use "/Users/kevinshuey/Github/Assignments/cuhksz_ECO3121/as2/aghousehold.dta"
gen yield=d32/d31
gen rental_in_share = c10/d31*100
gen rental_out_share = c13/d31*100

egen mean_f9 = mean(f9)
replace f9 = mean_f9 if f9 == .
drop mean_f9

egen mean_f25 = mean(f25)
replace f25 = mean_f25 if f25 == .
drop mean_f25

egen mean_f29 = mean(f29)
replace f29 = mean_f29 if f29 == .
drop mean_f29

reg yield rental_in_share rental_out_share f9 f25 f29

reg yield huzhu_edu

gen rental_total = rental_in_share + rental_out_share
reg yield rental_in_share rental_total 
