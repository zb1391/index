# RPI Server Side
This is our server side application to the Index project. Its purpose is to act as a connector between clients and rpi's through a TCP server. It will also mainatin a database of usernames and passwords that will be used for authorization.


# Getting Ruby set up
The first thing you will need to do is make sure you have ruby installed on your computer. The best way of doing this is to follow the tutorial for RVM here. From what I understand RVM is a Ruby Version Management system and allows you to install and maintain different versions of ruby for different projects I like this tutorial: https://www.digitalocean.com/community/tutorials/how-to-install-ruby-on-rails-on-ubuntu-12-04-lts-precise-pangolin-with-rvm

You may run into an error upon installation of the `curl` command. According to rvm's page: https://rvm.io/rvm/install you need to run this line before the curl command:

```
gpg --keyserver hkp://keys.gnupg.net --recv-keys 409B6B1796C275462A1703113804BB82D39DC0E3
```

Then you should hopefully be able to do the rest of the stuff needed. 

After you install ruby, you will need to run the `bundle` command. This is how you install the external libraries for the project that we will be using.
```
$ cd server
$ bundle install
```

# Getting the rest set up
We are using a gem called 'dotenv'. This allows us to create `environment variables` to be used within our application. Think of envionment variables almost like global variables that are created in separate files. Why do we need this? The point of this is to create a file with sensative variable information (like ip addresses or passwords) that we dont want to share with the public but are necessary for our application. You will need to get Zac's .env file for the application to work. 

## Example of a .env file
Lets say we have a password we dont want to share but we need to use in our application. Maybe to connect to a database or something. You create a .env file like this:
```
# .env
MY_PASSWORD="password123"
```

You then can access them using `ENV[]`
``` ruby
# in a ruby file
require 'dotenv'
Dotenv.load

user = User.create(username: 'test_user', password: ENV["MY_PASSWORD"] ) 
```
It is important to note that our application's `environment.rb` is like our global config file, so takes care of loading the .env file, so in our case the first two lines are no longer necessary. All you have to do in our files is `ENV["MY_PASSWORD"]` to reference the variables.

# Preparing the Database
We are not a rails application. This is a pure ruby project using active record and sqlite. Because of this a lot of the migration helpers normally accessible to us are missing. I created my own simple rake tasks to handle database migrations. If you look in the `db/migrate` folder is where all of the migration files are stored. It is a group of files that are preceded by timestamps. These timestamps allow the files to be stored and run in sequential order. The migrations prepare the database for us.

To set up your database
```
$ rake migrate
``` 
Rake is a ruby thing which allows you to perform project specific tasks. I created our own migration task to set up the database for us.

# Testing
We will be using rspec to do our testing. Ill have a tutorial explaining the testing process in ruby soon. Before you can really start writing code, we are going to need to set up our testing environment as well. We create our own separate test database to handle our test data.
```
$ rake migrate ENVIRONMENT="test"
```
Rspec is a testing framework similar to check in C. All you need to do is run the command to run all of the tests in the `spec/` folder
```
$ rspec
```

Make sure that is working before you start working

# About the project structure
There is a database component to this project. I have decided to use sqlite for our db for a couple reasons. Most important is that it require very little set up. There is no installation required because sqlite just keeps track of the db as a single file. 
