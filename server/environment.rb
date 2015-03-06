require 'yaml'
require 'active_record'
require 'pg'
require 'logger'
require 'colorize'
require 'rspec'
require 'dotenv'

Dotenv.load
ENV["ENVIRONMENT"] ||= "development"


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