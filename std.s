.arch armv7ve
.arm
.fpu vfpv4

.macro mov32, cond, reg, val
    movw\cond \reg, #:lower16:\val
    movt\cond \reg, #:upper16:\val
.endm

.data 

.text
.global bubblesort
.type bubblesort, %function
bubblesort:
.L0 :
	push {r10,fp}
	sub sp,sp,#8
	add fp,sp,#0
	str r0,[fp,#4]
	mov r5,#0
	str r5,[fp]
	b .L1
.L1 :
	ldr r0,[fp]
	mov r4,#8
	add fp,fp,r4
	mov sp,fp
	pop {r10,fp}
	bx lr
.global main
.type main, %function
main:
.L2 :
	push {r10,fp,lr}
	sub sp,sp,#56
	add fp,sp,#0
	mov r5,#0
	mov r6,#4
	mul r6,r5,r6
	str r6,[fp,#44]
	mov r4,#4
	add r5,fp,r4
	ldr r6,[fp,#44]
	add r6,r5,r6
	str r6,[fp,#48]
	mov r5,#4
	ldr r4,[fp,#48]
	str r5,[r4]
	mov r4,#4
	add r0,fp,r4
	bl bubblesort
	str r0,[fp,#52]
	mov r5,#0
	str r5,[fp]
	b .L3
.L3 :
	ldr r0,[fp]
	mov r4,#56
	add fp,fp,r4
	mov sp,fp
	pop {r10,fp,lr}
	bx lr
