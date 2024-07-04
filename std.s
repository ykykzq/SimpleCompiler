.arch armv7ve
.arm
.fpu vfpv4

.macro mov32, cond, reg, val
    movw\cond \reg, #:lower16:\val
    movt\cond \reg, #:upper16:\val
.endm

.data 

.text
.global main
.type main, %function
main:
.L0 :
	push {r10,fp}
	sub sp,sp,#44
	add fp,sp,#0
	mov r5,#1
	mov r6,#3
	mul r6,r5,r6
	str r6,[fp,#28]
	ldr r5,[fp,#28]
	mov r6,#2
	add r6,r5,r6
	str r6,[fp,#32]
	ldr r5,[fp,#32]
	mov r6,#4
	mul r6,r5,r6
	str r6,[fp,#36]
	mov r4,#4
	add r5,fp,r4
	ldr r6,[fp,#36]
	add r6,r5,r6
	str r6,[fp,#40]
	mov r5,#1
	ldr r4,[fp,#40]
	str r5,[r4]
	mov r5,#0
	str r5,[fp]
	b .L1
.L1 :
	ldr r0,[fp]
	mov r4,#44
	add fp,fp,r4
	mov sp,fp
	pop {r10,fp}
	bx lr
