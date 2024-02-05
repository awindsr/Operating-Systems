
function fibonacci() {
	local a=0
	local b=1
	if [ $1 -le 0 ]; then
		echo "0"
	elif [ $1 -eq 1 ]; then 
		echo "1"
	else
		for ((i=2; i<=$1; i++)); do
			local c=$((a + b))
			a=$b
			b=$c
			echo -n "$c " 
		done
	fi
}

read -p "Enter a limit: " n 
echo "Fibonacci Series up to $n terms:"
fibonacci $n



