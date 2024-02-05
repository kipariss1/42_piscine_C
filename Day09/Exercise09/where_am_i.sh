ips=$(ip -4 -o address | cut -d "/" -f1)
if [ -n "$ips" ]; then
	echo "$ips"
else
	echo "Je suis perdu!"
fi
