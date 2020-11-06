%% 5
u = pi/1000:0.1:pi/2;
v = -pi:0.1:pi;
[u,v] = meshgrid(u,v);
x = 2*sin(u).*csc(v);
y = cos(u).*csc(v);
z = 4*cot(v);
mesh(x,y,z)



%% 1
syms x y
z = exp(x+2*y)-sin(x);
z_x = diff(z,x)
z_y = diff(z,y)


%% 2
syms x y
z = asin(x/y^2);
diff(z,x,2)
diff(diff(z,y),x)
diff(z,y,2)
diff(diff(z,x),y)


%% 3
syms x y z F
F = y^z-2*x-z^x;
z_x = -diff(F,x)/diff(F,z)
z_y = -diff(F,y)/diff(F,z)


%% 4
clear
syms x y
z = x^4+y^4-4*x*y+1;
diff(z,x)
diff(z,y)
[x,y] = solve('4*x^3 - 4*y=0','4*y^3 - 4*x=0','x','y')

clear
syms x y
z = x^4+y^4-4*x*y+1;
A = diff(z,x,2)
B = diff(diff(z,x),y)
C = diff(z,y,2)

ezsurf('x^4+y^4-4*x*y+1')
