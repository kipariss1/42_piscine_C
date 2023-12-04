str1='\';
str2="'";
str3='?';
str4='"';
str5='\';
str6='"';
str7="'";
str8='\';
FT_NBR1=$str1$str2$str3$str4$str5$str6$str7$str8;
FT_NBR1_5_base=$(echo $FT_NBR1 | tr "'\\" 01 | tr "\"?!" 234);
echo $FT_NBR1_5_base;

FT_NBR2="rcrdmddd";
FT_NBR2_5_base=$(echo $FT_NBR2 | tr "mrdoc" 01234);
echo $FT_NBR2_5_base;

res_13_base=$(echo "obase=13; ibase=5; $FT_NBR1_5_base+$FT_NBR2_5_base;" | bc);
echo $res_13_base;
echo $res_13_base | tr 0123456789ABC 'gtaio luSnemf';
