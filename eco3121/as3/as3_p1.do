use "/Users/kevinshuey/Github/coursework/eco3121/as3/Rainfall.dta", clear
tostring vl_id, replace
save Rainfall_temp.dta, replace

use aghousehold.dta, clear
gen yield=d32/d31
gen lyield = ln(yield)

merge m:1 vl_id using Rainfall_temp.dta
drop if missing(d31) | missing(c13) | missing(av_rain) | missing(lyield)

gen rental_out_share = c13/d31*100
reg rental_out_share av_rain

predict rental_out_share_hat
reg lyield rental_out_share_hat

ivreg lyield (rental_out_share = av_rain)

save aghousehold_temp.dta
use aghousehold_temp.dta, clear
drop _merge
gen vl_id2 = substr(vl_id, 1, 2)
merge m:1 vl_id2 using landlaw.dta
drop if missing(implemented) | missing(av_rain) | missing(lyield) /*
*/| missing(rental_out_share)


reg rental_out_share av_rain implemented
test av_rain implemented


ivreg lyield (rental_out_share = av_rain implemented)
predict lyield_hat

gen resid = lyield - lyield_hat

reg resid rental_out_share av_rain implemented 
test av_rain implemented 


