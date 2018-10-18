.text
.globl main
main:
	move $t0,$0
	move $t1,$0
	addi $t1,10
    la $t2,Data
    
    la $a0,str2
    li $v0,4
    syscall
    
    
Loop1:
	la $a0,str1
	li $v0,4
	syscall

	li $v0,5
	syscall
    
	move $t3,$t0
	mul $t3,$t3,4
	add $t3,$t3,$t2
    sw $v0,0($t3)
	addi $t0,1
    
	beq $t0,$t1,Exit1
    
    j Loop1
    
Exit1:
    move $t0,$0
    move $t3,$t2
    
Loop2:

    move $t3,$t0
	mul $t3,$t3,4
	add $t3,$t3,$t2

    la $a0,str3
    li $v0,4
    syscall

    lw $a0,0($t3)
    li $v0,1
    syscall

    la $a0,str4
    li $v0,4
    syscall
    
	addi $t0,1
    
	beq $t0,$t1,Exit2
    
    j Loop2
    
Exit2:
   move $t4,$0
loop3:
    move $t6,$0

loop4:
   move $t7,$t6
   mul $t7,$t7,4
   add $t8,$t2,$t7
   lw $t9,0($t8)
   
   addi $t7,$t6,1
   mul $t7,$t7,4
   add $t0,$t2,$t7
   lw $t3,0($t0)
   
   bge $t9,$t3,THEN
   sw $t3,0($t8)
   sw $t9,0($t0)
THEN:
    addi $t6,$t6,1
    addi $t5,$t6,1
    sub $t5,$t1,$t5
    blt $0,$t5,loop4
    addi $t4,$t4,1
    beq $t4,$t1,EXIT3
    j loop3
    
    
EXIT3:
    move $t0,$0
loop5:
    move $t3,$t0
	mul $t3,$t3,4
	add $t3,$t3,$t2
    
    lw $a0,0($t3)
    li $v0,1
    syscall
    
    la $a0,str4
    li $v0,4
    syscall

    addi $t0,$t0,1
    bne $t0,$t1,loop5
    
    
    li $v0,10
    syscall
    
    
.data
	Data:   .space 40
    str2:   .asciiz "Please Input gross 10 Numbers blow!\n"
	str1:	.asciiz "Please Input Unsigned Number:"
    str3:   .asciiz "Output number:"
    str4:   .asciiz "\n"