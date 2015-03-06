ENV["ENVIRONMENT"] ||="test"
require_relative '../environment'
require 'rspec'
require 'database_cleaner'

RSpec.configure do |config|

	# before all tests are run
	config.before(:suite) do
		DatabaseCleaner.clean_with :truncation
		DatabaseCleaner.start
	end
end
