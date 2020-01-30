from PIL import Image
from PIL import ImageDraw
import random

img = Image.new('RGB', (420, 420), (28, 55, 99))
draw = ImageDraw.Draw(img)


class SnowFlake:

    def __init__(self, x, y):
        self.x = x
        self.y = y

    #  Returns whether two flakes are far enough or not
    def is_far_enough(self, flake):
        dist_x = abs(self.x - flake.x)
        dist_y = abs(self.y - flake.y)

        if dist_x > 10 or dist_y > 10:
            return True
        return False


class Snow:

    def __init__(self):
        random.seed()
        # Sets the number of snowflakes to be drawn.
        num_flakes = random.randint(40, 90)
        flakes = []
        num_failed = 0
        """ Adds snowflakes to list until the maximum is reached or the number of
        failed attempts grows too much. This assures more equal distribution of
        snowflakes while preventing an infinite loop.
        """
        while len(flakes) < num_flakes and num_failed < 1000:
            x = random.randint(0, img.size[0]-1)
            y = random.randint(0, img.size[1]-1)
            flake = SnowFlake(x, y)
            is_valid = True
            # Checks against each snowflake in list whether they are too close
            for i in range(len(flakes)):
                # If they are too close, new flake is created
                if not flakes[i].is_far_enough(flake):
                    is_valid = False
                    num_failed += 1
                    break
            if is_valid:
                flakes.append(flake)
        self.draw(flakes)

    #  Draws all constructed snowflakes
    def draw(self, flakes):
        for flake in flakes:
            size = random.randint(4, 15)
            line_width = int(size/4)-1
            self.add_snowflake(flake, size, line_width)

    #  Adds a flake to the picture
    def add_snowflake(self, flake, size, line_width):
        colour = (145, 187, 255)
        x = flake.x
        y = flake.y

        #  Diagonal line UL-DR
        draw.line((x - size, y - size, x + size, y + size), colour, line_width)
        # Diagonal line UR-DL
        draw.line((x + size, y - size, x - size, y + size), colour, line_width)
        # Extends the length of horizontal and vertical lines
        size += 4
        # horizontal line
        draw.line((x + size, y, x - size, y), colour, line_width)
        # vertical line
        draw.line((x, y - size, x, y + size), colour, line_width)


class SnowBall:

    def __init__(self, x, y, radius, colors=('white', 'black')):
        self.x = x
        self.y = y
        self.radius = radius
        self.colors = colors

    #  Returns the x and y coordinates and radius of the ball
    def get_position(self):
        return {'x': self.x, 'y': self.y, 'radius': self.radius}

    #  Draws the ball to the picture
    def draw(self):
        r = self.radius
        draw.ellipse((self.x - r, self.y - r, self.x + r, self.y + r),
                     self.colors[0], self.colors[1])


class SnowMan:
    __balls = []

    def __init__(self, floor=400, x=200, base_radius=80, difference=20):
        self.floor = floor
        self.x = x
        self.base_radius = base_radius
        self.difference = difference

    #  Add a ball to snowman's body
    def __add_ball(self, index):
        if len(self.__balls) == 0:
            bottom = self.floor
            radius = self.base_radius
            x = self.x
        else:
            radius = (self.__balls[index-1].get_position()['radius']
                - self.difference)
            bottom = (self.__balls[index-1].get_position()['y']
                - self.__balls[index-1].get_position()['radius'])
            x = self.x
        new_snowball = SnowBall(x, bottom-radius, radius)
        self.__balls.append(new_snowball)

    #  Adds given number of balls to snowman
    def add_balls(self, i):
        for x in range(i):
            self.__add_ball(x)

    #  Draws snowman's nose
    def __draw_nose(self):
        ball = self.__balls[len(self.__balls)-1]
        y_cross = ball.y + int(ball.radius/2)
        x_cross = ball.x - int(ball.radius/3*2)
        draw.line((ball.x, ball.y + 15, x_cross, y_cross), 'orange', 4)
        draw.line((ball.x, ball.y, x_cross, y_cross), 'orange', 4)

    #  Draws both snowman's eyes.
    def __draw_eyes(self):
        ball = self.__balls[len(self.__balls)-1]
        x = int(ball.radius/3)
        y = int(ball.radius/4)
        self.__draw_eye(ball.x-x, ball.y-y)
        self.__draw_eye(ball.x+x, ball.y-y)

    #  Private method drawing single eye
    def __draw_eye(self, x, y):
        draw.ellipse((x-4, y-6, x+4, y+6), 'black', 'black')

    #  Private method drawing snowman's buttons
    def __draw_buttons(self, count):
        ball = self.__balls[len(self.__balls)-2]
        top = ball.y - ball.radius
        step = int(ball.radius*2/(count+1))
        for i in range(count):
            self.__draw_button(ball.x, top + (i + 1) * step)

    #  Draws a single button
    def __draw_button(self, x, y):
        draw.ellipse((x-4, y-5, x+4, y+5), 'black', 'black')

    #  Draws the entire snowman, his balls, eyes and nose.
    def draw(self):
        for ball in self.__balls:
            ball.draw()
        self.__draw_nose()
        self.__draw_eyes()
        self.__draw_buttons(5)


snow = Snow()

snow_man = SnowMan()

snow_man.add_balls(3)
snow_man.draw()

img.show()
