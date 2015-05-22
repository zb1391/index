require 'yaml'
require 'active_record'
require 'active_support/all'
# require 'pg'
require 'sqlite3'
require 'logger'
require 'colorize'
require 'rspec'
require 'dotenv'
require 'pry'
require 'json'
require 'socket'
Dotenv.load
ENV["ENVIRONMENT"] ||= "development"

# set the right port for windows clients based on environment
if ENV["ENVIRONMENT"] == "development"
	ENV["WINDOWS_PORT"] = '2000'
elsif ENV["ENVIRONMENT"] = "test"
	ENV["WINDOWS_PORT"] = '2001'
end

directories = ['./db/*','./lib/*']
directories.each do |dir|
	Dir.glob(dir).each do |folder|
		Dir.glob(folder+"/*.rb").each do |file|
			require file
		end
	end
end

configuration = YAML::load(IO.read('db/database.yml'))
ActiveRecord::Base.establish_connection(configuration[ENV["ENVIRONMENT"]])